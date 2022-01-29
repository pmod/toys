#!/bin/sh
docker build --tag python-test .

docker container run python-test

