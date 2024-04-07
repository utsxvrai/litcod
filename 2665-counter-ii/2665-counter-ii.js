/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    
    let s = init;
    
    function increment(){
        return  ++s;
    }
    function decrement(){
        return --s;
    }
    function reset(){
        return s = init;
    }
    
    return {increment, decrement, reset};
    
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */