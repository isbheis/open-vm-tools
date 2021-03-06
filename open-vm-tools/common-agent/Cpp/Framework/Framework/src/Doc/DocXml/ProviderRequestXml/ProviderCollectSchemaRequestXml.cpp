/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/ProviderRequestXml/ProviderRequestHeaderXml.h"

#include "Doc/ProviderRequestDoc/CProviderCollectSchemaRequestDoc.h"
#include "Doc/ProviderRequestDoc/CProviderRequestHeaderDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/ProviderRequestXml/ProviderCollectSchemaRequestXml.h"

using namespace Caf;

void ProviderCollectSchemaRequestXml::add(
	const SmartPtrCProviderCollectSchemaRequestDoc providerCollectSchemaRequestDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ProviderCollectSchemaRequestXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(providerCollectSchemaRequestDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string clientIdVal =
			BasePlatform::UuidToString(providerCollectSchemaRequestDoc->getClientId());
		CAF_CM_VALIDATE_STRING(clientIdVal);
		thisXml->addAttribute("clientId", clientIdVal);

		const std::string requestIdVal =
			BasePlatform::UuidToString(providerCollectSchemaRequestDoc->getRequestId());
		CAF_CM_VALIDATE_STRING(requestIdVal);
		thisXml->addAttribute("requestId", requestIdVal);

		const std::string pmeIdVal = providerCollectSchemaRequestDoc->getPmeId();
		CAF_CM_VALIDATE_STRING(pmeIdVal);
		thisXml->addAttribute("pmeId", pmeIdVal);

		const std::string jobIdVal =
			BasePlatform::UuidToString(providerCollectSchemaRequestDoc->getJobId());
		CAF_CM_VALIDATE_STRING(jobIdVal);
		thisXml->addAttribute("jobId", jobIdVal);

		const std::string outputDirVal = providerCollectSchemaRequestDoc->getOutputDir();
		CAF_CM_VALIDATE_STRING(outputDirVal);
		thisXml->addAttribute("outputDir", outputDirVal);

		const SmartPtrCProviderRequestHeaderDoc requestHeaderVal =
			providerCollectSchemaRequestDoc->getRequestHeader();
		CAF_CM_VALIDATE_SMARTPTR(requestHeaderVal);

		const SmartPtrCXmlElement requestHeaderXml =
			thisXml->createAndAddElement("requestHeader");
		ProviderRequestHeaderXml::add(requestHeaderVal, requestHeaderXml);
	}
	CAF_CM_EXIT;
}

SmartPtrCProviderCollectSchemaRequestDoc ProviderCollectSchemaRequestXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ProviderCollectSchemaRequestXml", "parse");

	SmartPtrCProviderCollectSchemaRequestDoc providerCollectSchemaRequestDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string clientIdStrVal =
			thisXml->findRequiredAttribute("clientId");
		UUID clientIdVal = CAFCOMMON_GUID_NULL;
		if (! clientIdStrVal.empty()) {
			BasePlatform::UuidFromString(clientIdStrVal.c_str(), clientIdVal);
		}

		const std::string requestIdStrVal =
			thisXml->findRequiredAttribute("requestId");
		UUID requestIdVal = CAFCOMMON_GUID_NULL;
		if (! requestIdStrVal.empty()) {
			BasePlatform::UuidFromString(requestIdStrVal.c_str(), requestIdVal);
		}

		const std::string pmeIdVal =
			thisXml->findRequiredAttribute("pmeId");

		const std::string jobIdStrVal =
			thisXml->findRequiredAttribute("jobId");
		UUID jobIdVal = CAFCOMMON_GUID_NULL;
		if (! jobIdStrVal.empty()) {
			BasePlatform::UuidFromString(jobIdStrVal.c_str(), jobIdVal);
		}

		const std::string outputDirStrVal =
			thisXml->findRequiredAttribute("outputDir");
		const std::string outputDirVal = outputDirStrVal;

		const SmartPtrCXmlElement requestHeaderXml =
			thisXml->findRequiredChild("requestHeader");

		SmartPtrCProviderRequestHeaderDoc requestHeaderVal;
		if (! requestHeaderXml.IsNull()) {
			requestHeaderVal = ProviderRequestHeaderXml::parse(requestHeaderXml);
		}

		providerCollectSchemaRequestDoc.CreateInstance();
		providerCollectSchemaRequestDoc->initialize(
			clientIdVal,
			requestIdVal,
			pmeIdVal,
			jobIdVal,
			outputDirVal,
			requestHeaderVal);
	}
	CAF_CM_EXIT;

	return providerCollectSchemaRequestDoc;
}

