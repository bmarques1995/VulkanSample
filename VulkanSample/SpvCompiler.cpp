#include "SpvCompiler.h"



void CompileVertex(std::string shader, ComPtr<IDxcBlob>* resultBlob)
{
	ComPtr<IDxcUtils> dxcUtils;
	ComPtr<IDxcCompiler3> dxcCompiler;
	DxcCreateInstance(CLSID_DxcUtils, IID_PPV_ARGS(dxcUtils.GetAddressOf()));
	DxcCreateInstance(CLSID_DxcCompiler, IID_PPV_ARGS(dxcCompiler.GetAddressOf()));

	DxcBuffer shaderBuffer;
	shaderBuffer.Ptr = shader.c_str();
	shaderBuffer.Size = shader.length();
	shaderBuffer.Encoding = 0;
		
	std::vector<LPCWSTR> args;

	args.push_back(L"-Zpc");
	args.push_back(L"-HV");
	args.push_back(L"2021");
	args.push_back(L"-T");
	args.push_back(L"vs_6_0");
	args.push_back(L"-E");
	args.push_back(L"main");
	args.push_back(L"-spirv");
	args.push_back(L"-fspv-target-env=vulkan1.3");

	ComPtr<IDxcResult> result;
	dxcCompiler->Compile(&shaderBuffer, args.data(), args.size(), nullptr, IID_PPV_ARGS(result.GetAddressOf()));

	result->GetOutput(DXC_OUT_OBJECT, IID_PPV_ARGS(resultBlob->GetAddressOf()), nullptr);
}

void CompilePixel(std::string shader, ComPtr<IDxcBlob>* resultBlob)
{
	ComPtr<IDxcUtils> dxcUtils;
	ComPtr<IDxcCompiler3> dxcCompiler;
	DxcCreateInstance(CLSID_DxcUtils, IID_PPV_ARGS(dxcUtils.GetAddressOf()));
	DxcCreateInstance(CLSID_DxcCompiler, IID_PPV_ARGS(dxcCompiler.GetAddressOf()));

	DxcBuffer shaderBuffer;
	shaderBuffer.Ptr = shader.c_str();
	shaderBuffer.Size = shader.length();
	shaderBuffer.Encoding = 0;

	std::vector<LPCWSTR> args;

	args.push_back(L"-Zpc");
	args.push_back(L"-HV");
	args.push_back(L"2021");
	args.push_back(L"-T");
	args.push_back(L"ps_6_0");
	args.push_back(L"-E");
	args.push_back(L"main");
	args.push_back(L"-spirv");
	args.push_back(L"-fspv-target-env=vulkan1.3");

	ComPtr<IDxcResult> result;
	dxcCompiler->Compile(&shaderBuffer, args.data(), args.size(), nullptr, IID_PPV_ARGS(result.GetAddressOf()));

	result->GetOutput(DXC_OUT_OBJECT, IID_PPV_ARGS(resultBlob->GetAddressOf()), nullptr);
}
