/*
    DataTypeClass: HistoryEventFieldList

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/HistoryEventFieldList.h"

namespace OpcUaStackCore
{
    
    HistoryEventFieldList::HistoryEventFieldList(void)
    : Object()
    , ExtensionObjectBase()
    , eventFields_()
    {
    }
    
    HistoryEventFieldList::~HistoryEventFieldList(void)
    {
    }
    
    OpcUaVariantArray&
    HistoryEventFieldList::eventFields(void)
    {
        return eventFields_;
    }
    
    bool
    HistoryEventFieldList::operator==(const HistoryEventFieldList& value)
    {
        HistoryEventFieldList* dst = const_cast<HistoryEventFieldList*>(&value);
        if (eventFields_ != dst->eventFields()) return false;
        return true;
    }
    
    bool
    HistoryEventFieldList::operator!=(const HistoryEventFieldList& value)
    {
        return !this->operator==(value);
    }
    
    void
    HistoryEventFieldList::copyTo(HistoryEventFieldList& value)
    {
        eventFields_.copyTo(value.eventFields());
    }
    
    HistoryEventFieldList&
    HistoryEventFieldList::operator=(const HistoryEventFieldList& value)
    {
        const_cast<HistoryEventFieldList*>(&value)->copyTo(*this);
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
    HistoryEventFieldList::factory(void)
    {
    	return constructSPtr<HistoryEventFieldList>();
    }
    
    std::string
    HistoryEventFieldList::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    HistoryEventFieldList::typeName(void)
    {
    	return "HistoryEventFieldList";
    }
    
    OpcUaNodeId
    HistoryEventFieldList::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)920,0);
    }
    
    OpcUaNodeId
    HistoryEventFieldList::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)922, 0);
    }
    
    OpcUaNodeId
    HistoryEventFieldList::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)921, 0);
    }
    
    OpcUaNodeId
    HistoryEventFieldList::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15349, 0);
    }
    
    void
    HistoryEventFieldList::opcUaBinaryEncode(std::ostream& os) const
    {
        eventFields_.opcUaBinaryEncode(os);
    }
    
    void
    HistoryEventFieldList::opcUaBinaryDecode(std::istream& is)
    {
        eventFields_.opcUaBinaryDecode(is);
    }
    
    bool
    HistoryEventFieldList::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    HistoryEventFieldList::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    HistoryEventFieldList::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "HistoryEventFieldList encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    HistoryEventFieldList::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!eventFields_.xmlEncode(elementTree, "Variant", xmlns)) {
            Log(Error, "HistoryEventFieldList encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EventFields", elementTree));
    
        return true;
    }
    
    bool
    HistoryEventFieldList::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryEventFieldList decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    HistoryEventFieldList::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("EventFields");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryEventFieldList decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!eventFields_.xmlDecode(*tree, "Variant", xmlns)) {
            Log(Error, "HistoryEventFieldList decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    HistoryEventFieldList::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        boost::property_tree::ptree elementTree;
        if (!jsonEncode(elementTree)) {
    	     Log(Error, "HistoryEventFieldList json encoder error")
    		     .parameter("Element", element);
     	     return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    HistoryEventFieldList::jsonEncode(boost::property_tree::ptree& pt)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!eventFields_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "HistoryEventFieldList json encoder error")
    		     .parameter("Element", "eventFields_");
            return false;
        }
        pt.push_back(std::make_pair("EventFields", elementTree));
    
        return true;
    }
    
    bool
    HistoryEventFieldList::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
        boost::optional<boost::property_tree::ptree&> tmpTree;
    
        tmpTree = pt.get_child_optional(element);
        if (!tmpTree) {
     	     Log(Error, "HistoryEventFieldList json decoder error")
    		    .parameter("Element", element);
    		 return false;
        }
        return jsonDecode(*tmpTree);
    }
    
    bool
    HistoryEventFieldList::jsonDecode(boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = "EventFields";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryEventFieldList decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!eventFields_.jsonDecode(*tree, "")) {
            Log(Error, "HistoryEventFieldList decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    HistoryEventFieldList::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	HistoryEventFieldList* dst = dynamic_cast<HistoryEventFieldList*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    HistoryEventFieldList::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	HistoryEventFieldList* dst = dynamic_cast<HistoryEventFieldList*>(&extensionObjectBase);
    	return *const_cast<HistoryEventFieldList*>(this) == *dst;
    }
    
    void
    HistoryEventFieldList::out(std::ostream& os)
    {
        os << "EventFields="; eventFields_.out(os);
    }

}
