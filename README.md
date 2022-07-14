# SerialMonitor_Qt

SerialMonitor on Qt

シリアルモニターを QT creator で作ってみました

<h2><a href="https://github.com/CaseyNelson314/SerialMonitor_Qt/releases/download/qt/SerialMonitorQt.zip">Download</a></h2>

## Demo

ポートが接続されると自動的に受信内容が表示されます

<img width=800 src="https://user-images.githubusercontent.com/91818705/171824071-a2f0f551-368a-47d0-868d-9301782ce182.png">

## Usage

### Monitor

  - Scroll
  
    初期状態では自動スクロール有効
  
    表示モニターをスクロールすると自動スクロールが解除されます
  
    有効にしたい場合は下までスクロールするか `Down` をクリック
  
  - Timestamp

    `☐Timestamp` にチェックを入れるとタイムスタンプを表示
  
  - BIN

    `☐BIN` にチェックを入れると二進数で表示
    
  - Line limit

    記録する最大行数を設定
    
    設定値を超えたら過去のデータから破棄

### Plottor
  
  - 未完成(グラフを表示する予定)
  

### Property

  - Log

    ログを表示
    
  - Port

    接続可能ポート一覧
    
  - Bluetooth

    Bluetooth ポートは接続できなかった場合固まるので除いています

    利用したい場合は `☐Bluetooth` にチェック
