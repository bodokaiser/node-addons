var chai   = require('chai');
var addons = require('../lib');

describe('Function', function() {

  describe('#create', function() {

    it('should return a function printing echo', function() {
      var echo = addons.function();

      chai.expect(echo()).to.equal('Hello World');
    });

  });

});
