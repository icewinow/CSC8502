#version 330 core

uniform sampler2D depthTex;
uniform sampler2D normTex;

uniform vec2 pixelSize;
uniform vec3 cameraPos;

uniform float lightRadius;
uniform vec3 lightPos;
uniform vec4 lightColour;
uniform vec3 Dirction;
uniform float OuterCutoff;
uniform float Cutoff;
uniform mat4 inverseProjView;
uniform float type;

out vec4 diffuseOutput;
out vec4 specularOutput;

void main(void){
   vec2 texCoord = vec2(gl_FragCoord.xy * pixelSize);
   float depth = texture(depthTex,texCoord.xy).r;
   vec3 ndcPos = vec3(texCoord,depth) * 2.0 - 1.0;
   vec4 invClipPos = inverseProjView * vec4(ndcPos,1.0);
   vec3 worldPos = invClipPos.xyz / invClipPos.w;
   

  /* if(type == 2){
   vec3 incident = normalize(-lightPos);
   vec3 normal = normalize(texture(normTex,texCoord.xy).xyz * 2.0 - 1.0);
   vec3 viewDir = normalize(cameraPos - worldPos);
   vec3 halfDir = normalize(incident + viewDir);

   float lambert = max(dot(incident,normal),0.0);
   float rFactor = clamp(dot(halfDir,normal),0.0,1.0);
   float specFactor = clamp(dot(halfDir,normal),0.0,1.0);

   specFactor = pow(specFactor,100.0);
   vec3 attenuated = lightColour.xyz;
   diffuseOutput = vec4(lightColour.xyz,1.0);
   specularOutput = vec4(lightColour.xyz * specFactor * 0.33,1.0);

   }*/
   if(type == 1){
   float dist = length(lightPos - worldPos);
   float atten = 1.0 - clamp(dist / lightRadius, 0.0, 1.0);
   vec3 incident = normalize(lightPos - worldPos);
   float theta = dot(incident,normalize(-Dirction));

   if(atten == 0.0 || theta < OuterCutoff){
      discard;
   }

   vec3 normal = normalize(texture(normTex,texCoord.xy).xyz * 2.0 - 1.0);
   vec3 viewDir = normalize(cameraPos - worldPos);
   vec3 halfDir = normalize(incident + viewDir);

   float epsilon = (Cutoff - OuterCutoff);
   float intensity = clamp((theta - OuterCutoff)/epsilon,0.0,1.0);

   float lambert = clamp(dot(incident,normal),0.0,1.0);
   float rFactor = clamp(dot(halfDir,normal),0.0,1.0);
   float specFactor = clamp(dot(halfDir,normal),0.0,1.0);

   specFactor = pow(specFactor,60.0);
   vec3 attenuated = lightColour.xyz * atten;
   diffuseOutput = vec4(attenuated * lambert,1.0);
   diffuseOutput *= intensity;
   specularOutput = vec4(attenuated * specFactor * 0.33,1.0);
   specularOutput *= intensity;

   }else if(type == 0){

   float dist = length(lightPos - worldPos);
   float atten = 1.0 - clamp(dist / lightRadius, 0.0, 1.0);

   if(atten == 0.0){
      discard;
   }

   vec3 incident = normalize(lightPos - worldPos);
   vec3 normal = normalize(texture(normTex,texCoord.xy).xyz * 2.0 - 1.0);
   vec3 viewDir = normalize(cameraPos - worldPos);
   vec3 halfDir = normalize(incident + viewDir);

   float lambert = clamp(dot(incident,normal),0.0,1.0);
   float rFactor = clamp(dot(halfDir,normal),0.0,1.0);
   float specFactor = clamp(dot(halfDir,normal),0.0,1.0);

   specFactor = pow(specFactor,60.0);
   vec3 attenuated = lightColour.xyz * atten;
   diffuseOutput = vec4(attenuated * lambert,1.0);
   specularOutput = vec4(attenuated * specFactor * 0.33,1.0);

   }
   
   
}
