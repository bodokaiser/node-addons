test: test-addons

build: build-addons

test-addons:
	./node_modules/.bin/mocha \
       	test/*.js

build-addons:
	./node_modules/.bin/node-gyp \
		configure build
