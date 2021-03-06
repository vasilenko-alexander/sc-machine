/*
-----------------------------------------------------------------------------
This source file is part of OSTIS (Open Semantic Technology for Intelligent Systems)
For the latest info, see http://www.ostis.net

Copyright (c) 2010-2014 OSTIS

OSTIS is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OSTIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with OSTIS.  If not, see <http://www.gnu.org/licenses/>.
-----------------------------------------------------------------------------
*/

#ifndef _builder_h_
#define _builder_h_

#include "types.h"

class iTranslator;
class iTranslatorFactory;

struct BuilderParams
{
    //! Input directory path
    String inputPath;
    //! Output directory path
    String outputPath;
    //! Path to memory extensions
    String extensionsPath;
    //! Flag to clear output
    bool clearOutput;
    //! Flag to generate format information based on file extensions
    bool autoFormatInfo;
    //! Path to configuration file
    String configFile;
};

class Builder
{
public:
    explicit Builder();
    virtual ~Builder();

    //! Initialize builder. Create and register translator factories
    void initialize();

    /*! Run building process
      * @param options Builder options
      * @returns If build finished, then returns ture; otherwise returns false
      */
    bool run(const BuilderParams &options);

    /*! Register new translator factory
     * @param factory Pointer to translator factory to register
     */
    void registerTranslator(iTranslatorFactory *factory);
    /*! Check if translator for specified file extension exists
     * @param ext File extension to check
     * @param If translator for specified file extension registered, then returns true; otherwise returns false
     */
    bool hasTranslator(const std::string &ext) const;

protected:


    //! Process specified file
    bool processFile(const String &filename);

    //! Collecting files for process
    void collectFiles();


private:
    //! Set of files to process
    typedef std::set< String > tFileSet;
    tFileSet mFileSet;

    //! Translator factories map
    typedef std::map<std::string, iTranslatorFactory*> tTranslatorFactories;
    tTranslatorFactories mTranslatorFactories;

    //! List of errors
    typedef std::list<std::string> tStringList;
    tStringList mErrors;

    //! Builder parameters
    BuilderParams mParams;

};

#endif
