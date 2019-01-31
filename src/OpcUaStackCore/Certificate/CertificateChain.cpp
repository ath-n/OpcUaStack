/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateChainrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/Certificate/CertificateChain.h"

namespace OpcUaStackCore
{

	CertificateChain::CertificateChain(void)
	: certificateVec_()
	{
	}

	CertificateChain::~CertificateChain(void)
	{
		certificateVec_.clear();
	}

	void
	CertificateChain::clear(void)
	{
		certificateVec_.clear();
	}

	Certificate::Vec&
	CertificateChain::certificateVec(void)
	{
		return certificateVec_;
	}

	void
	CertificateChain::addCertificate(Certificate::SPtr& certificate)
	{
		certificateVec_.push_back(certificate);
	}

	Certificate::SPtr
	CertificateChain::getCertificate(uint32_t idx)
	{
		if (idx >= certificateVec_.size()) {
			Certificate::SPtr certificate;
			return certificate;
		}
		return certificateVec_[idx];
	}

	uint32_t
	CertificateChain::size(void)
	{
		return certificateVec_.size();
	}

	uint32_t
	CertificateChain::lastCertificateSize(void)
	{
		if (certificateVec_.size() == 0) {
			return 0;
		}

		auto certificate = certificateVec_[certificateVec_.size()-1];
		return certificate->getDERBufSize();
	}

	bool
	CertificateChain::fromByteString(OpcUaByteString& byteString)
	{
		certificateVec_.clear();

		// get pointer to certificate chain
		char* certBuf = nullptr;
		int32_t certLen = 0;
		byteString.value(&certBuf, &certLen);
		if (certLen <= 0) {
			return false;
		}

		char* mem = certBuf;
		while (certLen > 0) {
			Certificate::SPtr certificate = constructSPtr<Certificate>();
			if (!certificate->fromDERBuf(certBuf, (uint32_t)certLen)) {
				certificate->log(Error, "decode certificate chain error - Certificate::fromDERBuf");
				return false;
			}
			certificateVec_.push_back(certificate);

			uint32_t len = certificate->getDERBufSize();
			if (len == 0) {
				Log(Error, "decode certificate chain error - DER buflen error");
				return false;
			}

			mem += len;
			certLen -= len;
		}

		return true;
	}

	bool
	CertificateChain::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByteString byteString;
		byteString.opcUaBinaryDecode(is);
		return fromByteString(byteString);
	}

	bool
	CertificateChain::toByteString(OpcUaByteString& byteString) const
	{
		if (certificateVec_.empty()) {
			return true;
		}

		// calculate buffer size
		uint32_t usedBufferSize = 0;
		for (auto certificate : certificateVec_) {
			usedBufferSize += certificate->getDERBufSize();
		}

		if (usedBufferSize == 0) {
			return true;
		}

		// create buffer
		MemoryBuffer buffer(usedBufferSize);
		char* mem = buffer.memBuf();
		for (auto certificate : certificateVec_) {
			uint32_t length = certificate->getDERBufSize();
			certificate->toDERBuf(mem, &length);

			mem += length;
		}

		byteString.value(buffer.memBuf(), buffer.memLen());
		return true;
	}

	bool
	CertificateChain::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaByteString byteString;
		toByteString(byteString);
		byteString.opcUaBinaryEncode(os);
		return true;
	}

}
