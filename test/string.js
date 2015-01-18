var chai   = require('chai');
var addons = require('../lib');

describe('String', function() {

  describe('value', function() {

    it('should equal "Hello World"', function() {
      chai.expect(addons.string.value).to.equal('Hello World');
    });

  });

  describe('#greet', function() {

    it('should return "Hello Joe"', function() {
      chai.expect(addons.string.greet("Joe")).to.equal('Hello Joe');
    });

  });

});
