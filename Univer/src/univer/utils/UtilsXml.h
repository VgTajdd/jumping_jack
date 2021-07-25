// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// UtilsXml.h                                                                //
// ========================================================================= //

#ifndef UTILS_XML_H_
#define UTILS_XML_H_

#include <string>
#include <memory>

#include <rapidxml_utils.hpp>
#include <rapidxml.hpp>
#include <rapidxml_print.hpp>

#include <univer/core/UDefines.h>

namespace univer::utils
{
typedef ::rapidxml::xml_node<> XmlNode;
typedef ::rapidxml::xml_document<> XmlDocument;
typedef ::rapidxml::xml_attribute<> XmlAttribute;

class XmlLoader
{
public:
	UVR_API static std::unique_ptr<XmlLoader> Create();
public:
	UVR_API XmlLoader();
	UVR_API ~XmlLoader();
	UVR_API XmlNode* parseFromString( const std::string& xmlString );
	UVR_API XmlNode* parseFromFile( const std::string& filename );
private:
	std::unique_ptr< ::rapidxml::file<> > m_xmlFile;
	XmlDocument m_doc;
};

class UtilsXml
{
public:
	UVR_API explicit UtilsXml();
	UVR_API ~UtilsXml();
	UVR_API static XmlNode* createDefaultNode( XmlDocument& doc );
	UVR_API static XmlNode* createNode( XmlDocument* doc, const char* name );
	UVR_API static XmlNode* createNode( XmlDocument* doc, const std::string& name, const std::string& value );

	UVR_API static XmlNode* createNodeInt( XmlDocument* doc, const std::string& name, const int value );
	UVR_API static XmlNode* createNodeInt64( XmlDocument* doc, const std::string& name,	const int64_t value );
	UVR_API static XmlNode* createNodeDouble( XmlDocument* doc, const std::string& name, const double value );
	UVR_API static XmlNode* createNodeBool( XmlDocument* doc, const std::string& name, const bool value );

	UVR_API static std::string readStringFromFirstNode( XmlNode* node, const char* name, bool& ok );
	UVR_API static std::string readStringFromNode( XmlNode* node, bool& ok );
	UVR_API static int readIntFromNode( XmlNode* node, const char* name, bool& ok );
	UVR_API static double readDoubleFromNode( XmlNode* node, const char* name, bool& ok );
	UVR_API static bool readBoolFromNode( XmlNode* node, const char* name, bool& ok );

	UVR_API static XmlAttribute* createAttr( XmlDocument* doc, const char* name, const std::string& value );
	UVR_API static XmlAttribute* createAttrInt( XmlDocument* doc, const char* name,	const int value );
	UVR_API static XmlAttribute* createAttrInt64( XmlDocument* doc, const char* name, const uint64_t value );
	UVR_API static XmlAttribute* createAttrDouble( XmlDocument* doc, const char* name, const double& value );
	UVR_API static XmlAttribute* createAttrBoolean( XmlDocument* doc, const char* name, const bool& value );

	UVR_API static std::string readStringFromAttr( XmlNode* node, const std::string& nameField, bool& ok );
	UVR_API static int readIntFromAttr( XmlNode* node, const std::string& nameField, bool& ok );
	UVR_API static double readDoubleFromAttr( XmlNode* node, const std::string& nameField, bool& ok );
	UVR_API static bool readBooleanFromAttr( XmlNode* node, const std::string& nameField, bool& ok );
	UVR_API static void handle();
};
}
#endif