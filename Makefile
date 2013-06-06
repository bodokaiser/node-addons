check: test

test: test-sample

MOCHA_FLAGS = --require should

test-sample:
	./node_modules/.bin/mocha \
        $(MOCHA_FLAGS) test/*.js
