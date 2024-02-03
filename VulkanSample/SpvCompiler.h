#pragma once

#include <sstream>
#include <wrl.h>
#include <dxc/dxcapi.h>
#include <vector>

using Microsoft::WRL::ComPtr;

void CompileVertex(std::string shader, ComPtr<IDxcBlob>* resultBlob);
void CompilePixel(std::string shader, ComPtr<IDxcBlob>* resultBlob);