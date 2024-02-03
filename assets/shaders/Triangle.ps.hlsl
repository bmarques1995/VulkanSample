struct PS_Input
{
    float4 outPos : SV_POSITION;
    float3 fragColor : COLOR;
};

float4 main(PS_Input args) : SV_TARGET
{
    return float4(args.fragColor, 1.0f);
}