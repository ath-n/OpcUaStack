/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardNode.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

namespace OpcUaStackServer
{

	RegisterForwardNode::RegisterForwardNode(void)
	: nodes_()
	, resultCode_(Success)
	, forwardNodeSync_()
	, statuses_()
	{
	}

	RegisterForwardNode::RegisterForwardNode(const OpcUaNodeId& node)
	: nodes_()
	, resultCode_(Success)
	, forwardNodeSync_()
	, statuses_()
	{
		nodes_.push_back(node);
	}

	RegisterForwardNode::RegisterForwardNode(const std::vector<OpcUaNodeId>& nodes)
	: nodes_(nodes)
	, resultCode_(Success)
	, forwardNodeSync_()
	, statuses_()
	{
	}

	RegisterForwardNode::RegisterForwardNode(std::initializer_list<OpcUaNodeId> nodes)
	: nodes_(nodes)
	, resultCode_(Success)
	, forwardNodeSync_()
	, statuses_()
	{
	}

	RegisterForwardNode::~RegisterForwardNode(void)
	{
	}

	void
	RegisterForwardNode::addNode(const OpcUaNodeId& node)
	{
		nodes_.push_back(node);
	}

	void
	RegisterForwardNode::addNodes(const std::vector<OpcUaNodeId>& nodes)
	{
		nodes_.insert(nodes_.end(), nodes.begin(), nodes.end());
	}

	void
	RegisterForwardNode::node(const OpcUaNodeId& node)
	{
		nodes_.clear();
		nodes_.push_back(node);
	}

	void
	RegisterForwardNode::nodes(const std::vector<OpcUaNodeId>& nodes)
	{
		nodes_ = nodes;
	}

	std::vector<OpcUaNodeId>&
	RegisterForwardNode::nodes(void)
	{
		return nodes_;
	}

	void
	RegisterForwardNode::setReadCallback(Callback& callback)
	{
		forwardNodeSync_.readService().setCallback(callback);
	}

	void
	RegisterForwardNode::setWriteCallback(Callback& callback)
	{
		forwardNodeSync_.writeService().setCallback(callback);
	}

	void
	RegisterForwardNode::setReadHCallback(Callback& callback)
	{
		forwardNodeSync_.readHService().setCallback(callback);
	}

	void
	RegisterForwardNode::setReadHECallback(Callback& callback)
	{
		forwardNodeSync_.readHEService().setCallback(callback);
	}

	void
	RegisterForwardNode::setWriteHCallback(Callback& callback)
	{
		forwardNodeSync_.writeHService().setCallback(callback);
	}

	void
	RegisterForwardNode::setMethodCallback(Callback& callback)
	{
		forwardNodeSync_.methodService().setCallback(callback);
	}

	void
	RegisterForwardNode::setMonitoredItemStartCallback(Callback& callback)
	{
		forwardNodeSync_.monitoredItemStartService().setCallback(callback);
	}

	void
	RegisterForwardNode::setMonitoredItemStopCallback(Callback& callback)
	{
		forwardNodeSync_.monitoredItemStopService().setCallback(callback);
	}

	bool
	RegisterForwardNode::query(ApplicationServiceIf* applicationServiceIf, bool checkStatusCodeArray)
	{
		if (nodes_.size() == 0) return false;

		resultCode_ = Success;
		statuses_.clear();

		// create request
		auto trx = constructSPtr<ServiceTransactionRegisterForwardNode>();
		trx->request()->nodesToRegister()->resize(nodes_.size());
		for (auto node : nodes_) trx->request()->nodesToRegister()->push_back(constructSPtr<OpcUaNodeId>(node));
		trx->request()->forwardNodeSync()->updateFrom(forwardNodeSync_);

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) {
	  		return false;
	  	}

	  	// handle response
	  	bool result = true;
	  	if (checkStatusCodeArray) {
	  		for (uint32_t idx = 0; idx < trx->response()->statusCodeArray()->size(); idx++) {
	  			OpcUaStatusCode statusCode;
	  			trx->response()->statusCodeArray()->get(idx, statusCode);
	  			statuses_.push_back(statusCode);
	  			if (statusCode != Success) {
	  				result = false;
	  			}
	  		}
	  	}

		return result;
	}

	OpcUaStatusCode
	RegisterForwardNode::resultCode(void)
	{
		return resultCode_;
	}

	std::vector<OpcUaStatusCode>&
	RegisterForwardNode::statuses(void)
	{
		return statuses_;
	}

}
