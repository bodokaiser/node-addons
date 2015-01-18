var chai   = require('chai');
var addons = require('../lib');

describe('Boolean', function() {

  describe('value', function() {

    it('should be false', function() {
      chai.expect(addons.boolean.value).to.be.false;
    });

  });

  describe('#revert', function() {

    it('should return true for false', function() {
      chai.expect(addons.boolean.revert(false)).to.be.true;
    });

    it('should return false for true', function() {
      chai.expect(addons.boolean.revert(true)).to.be.false;
    });

  });

});
