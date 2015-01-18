var chai   = require('chai');
var addons = require('../lib');

describe('Object', function() {

  describe('value', function() {

    it('should be an object', function() {
      chai.expect(addons.object.value).to.be.a('object');
    });

  });

  describe('#get', function() {

    it('should equal b for key a', function() {
      var obj = { 'a': 'b' };

      chai.expect(addons.object.get(obj, 'a')).to.equal('b');
    });

  });

  describe('#set', function() {

    it('should set 200 on key "no"', function() {
      var obj = {};

      addons.object.set(obj, 'no', 200);

      chai.expect(obj).to.have.property('no', 200);
    });

  });

});
