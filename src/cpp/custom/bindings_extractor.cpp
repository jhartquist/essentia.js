/*
 * Copyright (C) 2006-2020  Music Technology Group - Universitat Pompeu Fabra
 *
 * This file is part of Essentia
 *
 * Essentia is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License as published by the Free
 * Software Foundation (FSF), either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the Affero GNU General Public License
 * version 3 along with this program.  If not, see http://www.gnu.org/licenses/
 */

#include <emscripten/bind.h>
#include "essentia_custom_extractor.h"

// expose the extractor class to js using embind templates
EMSCRIPTEN_BINDINGS(Class_Extractor) { 
  class_<LogMelSpectrogramExtractor>("LogMelSpectrogramExtractor")
    .constructor<int, int, int, std::string>()
    .property("version", &LogMelSpectrogramExtractor::essentiaVersion)
    .function("configure", &LogMelSpectrogramExtractor::configure)
    .function("compute", &LogMelSpectrogramExtractor::compute)
    .function("reset", &LogMelSpectrogramExtractor::reset)
    .function("shutdown", &LogMelSpectrogramExtractor::shutdown)
    ;
  // utility function to convert a Float32 JS typed array into std::vector<float>
  function("arrayToVector", &float32ArrayToVector);
  register_vector<float>("VectorFloat");
};
