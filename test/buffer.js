var chai = require('chai');

describe('Buffer', function() {

    var exports = require('../build/Release/buffer');

    describe('value', function() {

        it('should be a buffer', function() {
            chai.expect(exports.value).to.be.an.instanceof(Buffer);
        });

        it('should have length 5', function() {
            chai.expect(exports.value).to.have.length(5);
        });

    });

    describe('#create', function() {

        it('should return a Buffer containing "Hello"', function() {
            var buf = exports.create('Hello');

            chai.expect(buf).to.be.an.instanceof(Buffer);
            chai.expect(buf.toString()).to.equal('Hello');
        });

    });

    describe('#toString', function() {

        it('should return "Hello" for "Hello" buffer', function() {
            var buf = new Buffer('Hello');
            
            chai.expect(exports.toString(buf)).to.equal('Hello');
        });

    });

});
