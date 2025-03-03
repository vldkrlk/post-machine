# Maintainer: Nazar Tarasiuk <adidvar@gmail.com>
pkgname=post-machine
pkgver=0.3.6
pkgrel=1
pkgdesc="Post machine emulator"
arch=('x86_64')
url="https://github.com/adidvar/post-machine"
license=('GPL-3')
depends=('qt6-base')
makedepends=('git' 'cmake' 'qt6-base' 'qt6-tools')
source=("git+https://github.com/adidvar/post-machine.git")
md5sums=('SKIP')

build() {
    cd "$srcdir/$pkgname"

    # Create and enter the build directory
    mkdir -p build
    cd build

    # Run CMake configuration and build
    cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release
    make -j$(nproc)
}

package() {
    cd "$srcdir/$pkgname/build"

    # Install the built files
    make DESTDIR="$pkgdir/" install
}
