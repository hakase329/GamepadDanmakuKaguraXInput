# ダンマクカグラ専用コントローラー
ダンマクカグラタイプA用コントローラー

## 必須ライブラリ
[ArduinoXInput_AVR](https://github.com/dmadison/ArduinoXInput_AVR)
[ArduinoXInput_Sparkfun](https://github.com/dmadison/ArduinoXInput_SparkFun)
[ArduinoXInput](https://github.com/dmadison/ArduinoXInput)

### それぞれのREADMEにインストール方法が書かれているが、旧IDEの書き方が混ざっているため補足
- Arduino IDEの「基本設定」の「追加のボードマネージャのURL」に追加
```
https://raw.githubusercontent.com/dmadison/ArduinoXInput_Boards/master/package_dmadison_xinput_index.json
```

- ツールのボードマネージャを開き「XInput AVR Boards」と「XInput SparkFun Boards」の2個をインストール

- スケッチのライブラリインクルードでzip形式の～を選び「ArduinoXInput-x.x.x.zip」を追加

