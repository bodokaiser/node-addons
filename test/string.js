describe('String', function() {

    var chai = require('chai');
    var exports = require('../build/Release/string');

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
