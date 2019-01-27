{
  "targets": [
    { 
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "include_dirs" : [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "target_name": "n-api-stack-queue",
      "sources": [
        "src/index.cpp",
        "src/napiQueue/napiQueue.h",
        "src/napiQueue/napiQueue.сpp"
        "lib/base/queue/queue.h",
        "lib/base/queue/queue.сpp"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }
  ]
}