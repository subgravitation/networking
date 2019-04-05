PROJECT_ROOT=$1
BUILD_DIR=$2

if [ -d "$BUILD_DIR" ]
then
    rm -Rf $BUILD_DIR;
fi

mkdir -p $BUILD_DIR

cd $BUILD_DIR
cmake "$PROJECT_ROOT" -G "Unix Makefiles"
make
