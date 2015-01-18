var chai   = require('chai');
var addons = require('../lib');

describe('Array', function() {

  describe('value', function() {

    it('should be an array', function() {
      chai.expect(addons.array.value).to.be.a('array');
    });

  });

  describe('#push', function() {

    it('should push "Hello World"', function() {
      var arr = [];

      addons.array.push(arr, 'Hello World');

      chai.expect(arr[0]).to.equal('Hello World');
    });

  });

});
