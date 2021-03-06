var chai   = require('chai');
var addons = require('../lib');

describe('Number', function() {

  describe('value', function() {

    it('should be 666', function() {
      chai.expect(addons.number.value).to.equal(666);
    });

  });

  describe('#add', function() {

    it('should return 3000', function() {
      chai.expect(addons.number.add(2000, 1000)).to.equal(3000);
    });

  });

  describe('#substract', function() {

    it('should return 1000', function() {
      chai.expect(addons.number.substract(2000, 1000)).to.equal(1000);
    });

  });

  describe('#multiply', function() {

    it('should return 81', function() {
      chai.expect(addons.number.multiply(9, 9)).to.equal(81);
    });

  });

  describe('#divide', function() {

    it('should return 0xf', function() {
      chai.expect(addons.number.divide(0xfff, 0xff)).to.equal(0x10);
    });

  });

  describe('#power', function() {

    it('should return 256', function() {
      chai.expect(addons.number.power(2, 8)).to.equal(256);
    });

  });

});
