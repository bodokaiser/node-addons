var chai   = require('chai');
var addons = require('../lib');

describe('addons.Prototype', function() {

  it('should return an instance of addons.Prototype', function() {
    var proto = new addons.Prototype('test');

    chai.expect(proto).to.be.an.instanceof(addons.Prototype);
  });

  describe('#get', function() {

    it('should return "test"', function() {
      var proto = new addons.Prototype('test');

      chai.expect(proto.get('name')).to.equal('test');
    });

  });

  describe('#set', function() {

    it('should set "hello" to "world"', function() {
      var proto = new addons.Prototype('test');

      proto.set('hello', 'world');

      chai.expect(proto.get('hello')).to.equal('world');
    });

  });

});
