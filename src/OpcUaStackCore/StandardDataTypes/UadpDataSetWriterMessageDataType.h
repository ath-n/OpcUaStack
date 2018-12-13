/*
    DataTypeClass: UadpDataSetWriterMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UadpDataSetWriterMessageDataType_h__
#define __OpcUaStackCore_UadpDataSetWriterMessageDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetWriterMessageDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UadpDataSetWriterMessageDataType
    : public DataSetWriterMessageDataType
    {
      public:
        typedef boost::shared_ptr<UadpDataSetWriterMessageDataType> SPtr;
        typedef std::vector<UadpDataSetWriterMessageDataType::SPtr> Vec;
    
        UadpDataSetWriterMessageDataType(void);
        virtual ~UadpDataSetWriterMessageDataType(void);
        
        OpcUaUadpDataSetMessageContentMask& dataSetMessageContentMask(void);
        OpcUaUInt16& configuredSize(void);
        OpcUaUInt16& networkMessageNumber(void);
        OpcUaUInt16& dataSetOffset(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual OpcUaNodeId jsonTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonEncode(boost::property_tree::ptree& pt);
        virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(boost::property_tree::ptree& pt);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(UadpDataSetWriterMessageDataType& value);
        bool operator==(const UadpDataSetWriterMessageDataType& value);
        bool operator!=(const UadpDataSetWriterMessageDataType& value);
        UadpDataSetWriterMessageDataType& operator=(const UadpDataSetWriterMessageDataType& value);
    
      private:
        OpcUaUadpDataSetMessageContentMask dataSetMessageContentMask_;
        OpcUaUInt16 configuredSize_;
        OpcUaUInt16 networkMessageNumber_;
        OpcUaUInt16 dataSetOffset_;
    
    };
    
    class UadpDataSetWriterMessageDataTypeArray
    : public OpcUaArray<UadpDataSetWriterMessageDataType::SPtr, SPtrTypeCoder<UadpDataSetWriterMessageDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UadpDataSetWriterMessageDataTypeArray> SPtr;
    };

}

#endif
