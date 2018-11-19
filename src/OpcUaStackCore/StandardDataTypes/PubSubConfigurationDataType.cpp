/*
    DataTypeClass: PubSubConfigurationDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PubSubConfigurationDataType.h"

namespace OpcUaStackCore
{
    
    PubSubConfigurationDataType::PubSubConfigurationDataType(void)
    : Object()
    , ExtensionObjectBase()
    , publishedDataSets_()
    , connections_()
    , enabled_()
    {
    }
    
    PubSubConfigurationDataType::~PubSubConfigurationDataType(void)
    {
    }
    
    PublishedDataSetDataTypeArray&
    PubSubConfigurationDataType::publishedDataSets(void)
    {
        return publishedDataSets_;
    }
    
    PubSubConnectionDataTypeArray&
    PubSubConfigurationDataType::connections(void)
    {
        return connections_;
    }
    
    OpcUaBoolean&
    PubSubConfigurationDataType::enabled(void)
    {
        return enabled_;
    }
    
    bool
    PubSubConfigurationDataType::operator==(const PubSubConfigurationDataType& value)
    {
        PubSubConfigurationDataType* dst = const_cast<PubSubConfigurationDataType*>(&value);
        if (publishedDataSets_ != dst->publishedDataSets()) return false;
        if (connections_ != dst->connections()) return false;
        if (enabled_ != dst->enabled()) return false;
        return true;
    }
    
    bool
    PubSubConfigurationDataType::operator!=(const PubSubConfigurationDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    PubSubConfigurationDataType::copyTo(PubSubConfigurationDataType& value)
    {
        publishedDataSets_.copyTo(value.publishedDataSets());
        connections_.copyTo(value.connections());
        value.enabled_ = enabled_;
    }
    
    PubSubConfigurationDataType&
    PubSubConfigurationDataType::operator=(const PubSubConfigurationDataType& value)
    {
        const_cast<PubSubConfigurationDataType*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    PubSubConfigurationDataType::factory(void)
    {
    	return constructSPtr<PubSubConfigurationDataType>();
    }
    
    std::string
    PubSubConfigurationDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PubSubConfigurationDataType::typeName(void)
    {
    	return "PubSubConfigurationDataType";
    }
    
    OpcUaNodeId
    PubSubConfigurationDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15530,0);
    }
    
    OpcUaNodeId
    PubSubConfigurationDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21154, 0);
    }
    
    OpcUaNodeId
    PubSubConfigurationDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21178, 0);
    }
    
    OpcUaNodeId
    PubSubConfigurationDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21202, 0);
    }
    
    void
    PubSubConfigurationDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        publishedDataSets_.opcUaBinaryEncode(os);
        connections_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,enabled_);
    }
    
    void
    PubSubConfigurationDataType::opcUaBinaryDecode(std::istream& is)
    {
        publishedDataSets_.opcUaBinaryDecode(is);
        connections_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,enabled_);
    }
    
    bool
    PubSubConfigurationDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    PubSubConfigurationDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    PubSubConfigurationDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PubSubConfigurationDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!publishedDataSets_.xmlEncode(elementTree, "PublishedDataSetDataType", xmlns)) return false;
        pt.push_back(std::make_pair("PublishedDataSets", elementTree));
    
        elementTree.clear();
        if (!connections_.xmlEncode(elementTree, "PubSubConnectionDataType", xmlns)) return false;
        pt.push_back(std::make_pair("Connections", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, enabled_)) return false;
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        return true;
    }
    
    bool
    PubSubConfigurationDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PubSubConfigurationDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("PublishedDataSets");
        if (!tree) return false;
        if (!publishedDataSets_.xmlDecode(*tree, "PublishedDataSetDataType", xmlns)) return false;
    
        tree = pt.get_child_optional("Connections");
        if (!tree) return false;
        if (!connections_.xmlDecode(*tree, "PubSubConnectionDataType", xmlns)) return false;
    
        tree = pt.get_child_optional("Enabled");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, enabled_)) return false;
    
        return true;
    }
    
    bool
    PubSubConfigurationDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    PubSubConfigurationDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    PubSubConfigurationDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    PubSubConfigurationDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    PubSubConfigurationDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PubSubConfigurationDataType* dst = dynamic_cast<PubSubConfigurationDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PubSubConfigurationDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PubSubConfigurationDataType* dst = dynamic_cast<PubSubConfigurationDataType*>(&extensionObjectBase);
    	return *const_cast<PubSubConfigurationDataType*>(this) == *dst;
    }
    
    void
    PubSubConfigurationDataType::out(std::ostream& os)
    {
        os << "PublishedDataSets="; publishedDataSets_.out(os);
        os << ", Connections="; connections_.out(os);
        os << ", Enabled=" << enabled_;
    }

}
