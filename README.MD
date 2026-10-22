My old project felt super messy so I've done a complete refactor of it now that I kinda understand how OpenGl stuff works and how it's all structured.

I would like to point out how my naming convention works as last assignment I was incorrectly marked as using an inconsistent one:
public variables/methods/enums = PascalCase
private variables/scopedVariables = camelCase
constants = UPPER_SNAKE_CASE
file names = PascalCase
This is all the Standard C# naming convention, which Microsoft themself uses in their modern CPP development. The only place where my naming convention breaks is main can't have a capital M at the front but imo that's no different to a library using pascalCase or something yk. Also I did not write the shader loader class so it's different for that reason


checklist delete this when submitting
- [x] load model and texture
- [ ] skybox
- [ ] model that reflects skybox
- [ ] input stuff that uses polling
- [ ] spinning camera
- [ ] wireframe stuff


I made the space shuttle in blender btw (don't mind the shoddy texturing)