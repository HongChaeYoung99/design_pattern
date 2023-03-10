#pragma once
#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

struct ConfigAttribute
{
    std::string strAttribute;
    std::string strValue;
    bool bIsArray;
    std::vector<std::string> listValues;
    ConfigAttribute() { bIsArray = false; }
};

/** ConfigFile Class
 *
 */
class ConfigFile
{
public:
    ConfigFile();
    ConfigFile(std::string identifier);
    ConfigFile(std::string filename, std::string identifier, bool bAddDefaultsToConfig = true);
    virtual ~ConfigFile();

    //IO functions
    bool IsOpen();
    bool Save();
    bool SaveAs(std::string filename);
    bool IsModified();
    std::string LastError();

    //Get functions    
    std::string getString(std::string strAttribute, std::string strDefault);
    double getDouble(std::string strAttribute, double dDefault);
    int getInteger(std::string strAttribute, int iDefault);
    bool getBool(std::string strAttribute, bool bDefault);

    //The default case if overidden to simplify empty array defaults
    std::vector<std::string> getArray(std::string strAttribute, std::vector<std::string> listDefaults = std::vector<std::string>());

    std::vector<std::string> getAttributeList();
    std::vector<std::string> getValueList();

    //Set functions
    void setString(std::string strAttribute, std::string strValue);
    void setDouble(std::string strAttribute, double dValue);
    void setInteger(std::string strAttribute, int iValue);
    void setBool(std::string strAttribute, bool bValue);
    void setArray(std::string strAttribute, std::vector<std::string> listValues);

    //Serialization functions
    bool ImportXML(std::string strXML);
    std::string ExportXML();

    //Debug    
    void DumpConfig();

protected:
    virtual void LoadDefaults();
    bool ReadConfigFile();
    bool WriteConfigFile();


private:
    //returns the lowercase version of the input string
    static std::string Uppercase(std::string strInput);
    bool bIsModified;
    std::string m_strLastError;

    //Storage variables
    std::map<std::string, ConfigAttribute> m_mapConfig;
    std::string m_strFilename;
    std::string m_strIdentifier;

    bool m_bOpenSuccessful;
    //When true unitialized variables default values will be stored when requested with a get function.
    bool m_bAddDefaultsToConfig;

};

#endif /* CCONFIGFILE_H */