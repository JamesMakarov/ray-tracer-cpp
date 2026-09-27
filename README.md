# C++ Ray Tracer

[![C++ build and tests](https://github.com/JamesMakarov/ray-tracer-cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/JamesMakarov/ray-tracer-cpp/actions/workflows/ci.yml)

CPU renderer written in **C++** that generates a 500×500 image using ray casting, geometric intersection tests and Blinn-Phong lighting.

The project was developed for a Computer Graphics course and implements the rendering pipeline from scratch without relying on a graphics engine.

## Features

- perspective camera;
- ray/object intersection tests;
- spheres;
- cylinders;
- cones;
- box mesh;
- object instances with transformation matrices;
- translation and rotation;
- mirrored instance;
- ambient, diffuse and specular lighting;
- Blinn-Phong shading;
- hard shadows using shadow rays;
- solid-color and checker textures;
- multiple materials;
- anti-aliasing through multiple samples per pixel;
- interactive pixel picking after rendering;
- PPM image output.

## Project structure

```text
.
├── include/
│   ├── camera.h
│   ├── cone.h
│   ├── cylinder.h
│   ├── hittable.h
│   ├── hittable_list.h
│   ├── instance.h
│   ├── mat4.h
│   ├── material.h
│   ├── mesh.h
│   ├── ray.h
│   ├── sphere.h
│   ├── texture.h
│   ├── utils.h
│   ├── vec3.h
│   └── vec4.h
├── src/
│   └── main.cpp
└── output/
    └── imagem.ppm
```

## Rendering pipeline

For each output pixel, the renderer generates one or more rays from the camera into the scene.

When a ray hits an object, the renderer evaluates:

1. the surface material;
2. the surface normal;
3. ambient contribution;
4. visibility of the point light through a shadow ray;
5. diffuse contribution;
6. specular contribution using the Blinn-Phong model.

If no object is hit, a gradient background is returned.

## Scene

The current scene contains:

- a large textured ground sphere;
- a cylindrical central object;
- a red sphere;
- a cone;
- a mirrored cone instance;
- a rotated box mesh;
- a point light;
- a perspective camera.

The renderer uses 20 samples per pixel in the current configuration.

## Building

### Requirements

- a C++17-compatible compiler such as GCC/MinGW or Clang.

On Linux/macOS, compile with the included Makefile:

```bash
make
```

On Windows with MinGW, you can compile directly:

```bash
g++ -std=c++17 -O2 -Iinclude src/main.cpp -o ray-tracer.exe
```

## Tests

The repository includes lightweight C++ tests for the math primitives used by the renderer, including vector operations and transformation matrices.

Run:

```bash
make test
```

Build and tests also run automatically on GitHub Actions.

## Rendering an image

The renderer writes the PPM image to standard output and progress information to standard error.

Linux/macOS:

```bash
make render
```

The Makefile creates `output/` when necessary and writes the generated image to `output/imagem.ppm`.

Windows PowerShell:

```powershell
"-1" | .\ray-tracer.exe > output\imagem.ppm
```

The generated file uses the ASCII PPM (`P3`) format.

## Picking

After the render is complete, the program can receive pixel coordinates and fire the corresponding camera ray through the scene.

For a hit, it reports information such as:

- world-space hit point;
- surface normal;
- distance parameter;
- UV coordinates.

Enter `-1` to leave the picking mode.

## Notes

The renderer is intentionally educational: the geometry, matrices, camera, materials and lighting calculations are implemented directly in the project so the rendering process remains visible in the source code.
