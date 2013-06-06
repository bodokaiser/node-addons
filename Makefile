test: test-addons

build: build-addons

install: deps configure build

MOCHA_FLAGS = --require chai

deps:
	npm install -d

test-addons:
	./node_modules/.bin/mocha \
        $(MOCHA_FLAGS) test/*.js

build-addons:
	./node_modules/.bin/node-gyp \
		configure build
