[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<div align="center">
    <h3 align="center">Mandelbrot and Julia Set Visualizer</h3>
</div>

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#running-the-application">Running the Application</a></li>
      </ul>
    </li>
    <li><a href="#improvements">Improvements</a></li>
    <li><a href="#license">License</a></li>
  </ol>
</details>

## About The Project

<br/>
<div align="center">
    <img src="img/intro-screenshot.png" width="700">
</div>
<br/>

The Mandelbrot set is the set of numbers $c$ in the complex plane for which the iteration $z_{n+1} = z_{n}^{2} + c$ does
not
diverge to infinity when iterating starting from $z_{0} = 0$. As shown in the screenshot above, this application
displays two windows, the left of which plots the Mandelbrot set. For a given complex number $c_{0}$ hovered over by the
mouse pointer, the right window plots the corresponding Julia set consisting of numbers $z$ for which the function $z_
{n+1} = z_{n}^{2} + c_{0}$ does not diverge to infinity starting from $z_{0}=z$.

As you hover the mouse pointer over different points on the Mandelbrot set, watch as the right window transforms from
one Julia set to another. Because a different Julia set is generated for each point on the Mandelbrot set, the
Mandelbrot set can be considered a map of all Julia sets.

Below, we show some Julia sets along with their corresponding locations in the Mandelbrot set:

<div align="center">
    <img src="img/usage.png" width="700">
</div>

Additional features of the application on the Mandelbrot set window:

- `Left click` to zoom in and `right click` to zoom out.
- Press the `space bar` to restore the default scale.

### Built With

* [SDL2][sdl-url] Simple DirectMedia Layer
* [CMake][cmake-url] C++ build system

## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

The application uses `SDL2` to draw graphics on the screen. Consult the
official [installation website](https://wiki.libsdl.org/SDL2/Installation) for SDL2. Alternatively, you can install SDL2
and its dependencies on bash Linux by running the commands below:

```bash
$ sudo apt-get install build-essential git make \
pkg-config cmake ninja-build gnome-desktop-testing libasound2-dev libpulse-dev \
libaudio-dev libjack-dev libsndio-dev libx11-dev libxext-dev \
libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev \
libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev \
libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev fcitx-libs-dev \
libpipewire-0.3-dev libwayland-dev libdecor-0-dev
```

```bash
$ sudo apt-get install libsdl2-2.0-0 libsdl2-dev 
```

### Running the Application

The application uses `CMake` as a build system. To build and compile the application:

```bash
$ mkdir build
$ cd build
$ cmake -S .. -DCMAKE_BUILD_TYPE=Release
$ make
```

Then launch the application:

```bash
$ ./mandelbrot-visualizer
```

## Improvements

The nested loop in `Fractal::calculateIterationsAndHistogram` is the bottleneck in computing the pixels for the fractal.
However, this loop is an embarrassingly parallel workload, which can be decomposed to be completed by multiple threads
using [OpenMP](https://www.openmp.org/).

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[license-url]: LICENSE.txt

[linkedin-url]: https://www.linkedin.com/in/faerlin-pulido/

[sdl-url]: https://www.libsdl.org/

[cmake-url]: https://cmake.org/

[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge

[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
