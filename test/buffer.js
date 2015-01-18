var chai   = require('chai');
var addons = require('../lib');

describe('Buffer', function() {

  describe('value', function() {

    it('should be a buffer', function() {
      chai.expect(addons.buffer.value).to.be.an.instanceof(Buffer);
    });

    it('should have length 5', function() {
      chai.expect(addons.buffer.value).to.have.length(5);
    });

  });

  describe('#create', function() {

    it('should return a Buffer containing "Hello"', function() {
      var buf = addons.buffer.create('Hello');

      chai.expect(buf).to.be.an.instanceof(Buffer);
      chai.expect(buf.toString()).to.equal('Hello');
    });

  });

  describe('#toString', function() {

    it('should return "Hello" for "Hello" buffer', function() {
      var buf = new Buffer('Hello');

      chai.expect(addons.buffer.toString(buf)).to.equal('Hello');
    });

  });

});
