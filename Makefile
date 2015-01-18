SHELL := /bin/bash
PATH  := node_modules/.bin:$(PATH)

test: build
	@mocha test

build:
	@node-gyp configure build

install:
	@npm install --development

.PHONY: build
