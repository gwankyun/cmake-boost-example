# cmake-boost-example
Boost CMake使用例子

目前適配Windows及Boost 1.73版本

- `Boost_USE_STATIC_LIBS`默認為`ON`
- `Boost_USE_STATIC_RUNTIME`默認為`ON`
- `Boost_DIR`默認路徑為`C:/local/boost_1_73_0/lib64-msvc-14.2/cmake/Boost-1.73.0`

默認通過`USE_CXX_STD_17`使用`C++17`標準，可以設置為`OFF`令編譯器版本要求降到`C++11`

衹用`Boost`及標準庫，用到的`Boost`庫為：

- `Log` 日誌
- `Program options` 解析命令行參數
- `Asio` 網絡
- `Property Tree` 解析`XML`配置文件
- `Test` 單元測試
- `String Algo` 字符串算法
- `System` 系統錯誤碼
- `Serialization` 序列化
