#include "stereokit.hlsli"

//--name = sk/unlit
//--color:color = 1, 1, 1, 1
//--diffuse     = white
float4       color;
Texture2D    diffuse   : register(t0);
SamplerState diffuse_s : register(s0);

struct vsIn {
	float4 pos  : SV_Position;
	float3 norm : NORMAL0;
	float2 uv   : TEXCOORD0;
	float4 col  : COLOR0;
};
struct psIn {
	float4 pos   : SV_POSITION;
	float2 uv    : TEXCOORD0;
	float4 color : COLOR0;
	uint view_id : SV_RenderTargetArrayIndex;
};

psIn vs(vsIn input, uint id : SV_InstanceID) {
	psIn o;
	o.view_id = id % sk_view_count;
	id        = id / sk_view_count;

	float3 world = mul(float4(input.pos.xyz, 1), sk_inst[id].world).xyz;
	o.pos        = mul(float4(world,         1), sk_viewproj[o.view_id]);

	o.uv    = input.uv;
	o.color = input.col * color * sk_inst[id].color;
	return o;
}
float4 ps(psIn input) : SV_TARGET {
	float gamma = 2.2;
	float4 col = diffuse.Sample(diffuse_s, input.uv);

	col = col * input.color;
	col.rgb = pow(col.rgb, float3(gamma));

	return col; 
}
