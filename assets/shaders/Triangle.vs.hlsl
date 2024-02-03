#pragma pack_matrix(row_major)

struct VS_Input
{
    float2 inPosition : POSITION;
    float3 inColor : COLOR;
};

struct PS_Input
{
    float4 outPos : SV_POSITION;
    float3 fragColor : COLOR;
};

PS_Input main(VS_Input args)
{
    PS_Input prop;
    prop.outPos = float4(args.inPosition, 0.0f, 1.0f);
    prop.fragColor = args.inColor;
    return prop;
}