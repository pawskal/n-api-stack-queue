const addon = require('bindings')('n-api-stack-queue')

console.log(addon);
console.log(addon.hello());
console.log(addon.multiply(+'8', 5));

const { NapiQueue } = addon;

const queue = new NapiQueue();
console.dir(queue)

console.log(queue.enqueue({ superKeyVal: "SuperValueKey"} ),
)


console.log(queue.enqueue({ a: "test1" }))
queue.enqueue({ ad: "test3" })




  setTimeout(() => {
    const rc = queue.dequeue()
    const rb = queue.dequeue()
    const ra = queue.dequeue()

    console.log(rc
      , rb
      , ra
      )
    console.log('FINISH')
  }, 500);
