cd ..

PROJECT_ROOT=$(pwd)
BUILD_DIR="$PROJECT_ROOT/build/cmake"

cd ./build

sh build.sh $PROJECT_ROOT $BUILD_DIR
