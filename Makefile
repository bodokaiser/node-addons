test: test-boolean

build: build-boolean

install: deps configure build

MOCHA_FLAGS = --require chai

deps:
	npm install -d

configure:
	./node_modules/.bin/node-gyp \
		configure

build-boolean:
	./node_modules/.bin/node-gyp \
		build

test-boolean:
	./node_modules/.bin/mocha \
        $(MOCHA_FLAGS) test/*.js
