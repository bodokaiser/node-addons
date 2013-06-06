var chai = require('chai');

describe('String', function() {

    var exports = require('../build/RELEASE/string');

    describe('value', function() {

        it('should equal "Hello World"', function() {
            chai.expect(exports.value).to.equal('Hello World');
        });

    });

    describe('#greet', function() {

        it('should return "Hello Joe"', function() {
            chai.expect(exports.greet("Joe")).to.equal('Hello Joe');
        });

    });

});
