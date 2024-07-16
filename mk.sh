#! /bin/sh
# Auther: Albert Zhang<xhzzhang@yeah.net>
# Last Modified: 2022-11-10 15:53:12

usage()
{
  echo ""
  echo "Usage: $0 host [remote_app | subway_app | svm_app | pano_app | im_notify_app]"
  echo "host:"
  echo "       remote_app"
  echo "       subway_app"
  echo "       svm_app"
  echo "       pano_app"
  echo "       im_notify_app"
  echo ""
}

build()
{
  app_name=$1
	./generate_version.sh .version.h

  rm -rf build
  mkdir build
  cd build
  cmake -D cust_project:STRING=$app_name ..
  make -j8
}

clean()
{
  make clean -C build
}

case "$1" in
  "remote_app")
    build $1
  ;;

  "subway_app")
    build $1
  ;;

  "svm_app")
    build $1
  ;;

  "pano_app")
    build $1
  ;;

  "im_notify_app")
    build $1
  ;;

  "clean")
    clean
  ;;

  *)
    usage
  ;;

esac
