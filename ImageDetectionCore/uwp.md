・UWP概要
    -UWPとは（言葉の定義）
        かずきのUWP/ちょまどのブログ/kindle本
    -UWPアプリとは
        ・特徴
            -UWP上で動くアプリのこと
            -Win10デバイスすべてで動作可能（1バイナリ）
            -Win8のUniversalAppは、ソースコードレベルで共通だったが、UWPはバイナリレベル（確か。Kindle本だったか、かずきのUWPか。。）
            -作り方は後述（C#/XAMLとか）
            -.NetCore上で動く
            -WinRT利用（言い方あってる？）
        ・制限事項
            -sandboxで動作
            -管理者権限が必要な機能は原則不可
            -レジストリ操作も不可
            -他のアプリとの連携はUWPアプリとのみ可能（あってる？）
---
・UWP開発環境
    -必要環境（こういうの何て言うんだっけ？）
        ・VS2015以降
        ・Win10（Ver？）
    -開発手法（UIとロジック、用途）
        ・MS純正
            -C#（orVB）/XAML　⇒　一般的な手法（WPFの手法を踏襲）
            -C++/DirectX　⇒　ゲーム用
            -HTML/JavaScript　⇒　Webアプリ用
            -Xamarine.Forms（C#/XAML）　⇒　クロスプラットフォーム用
        ・サードパーティー
            -Cordova　⇒　クロスプラットフォーム用（よく知らない）
    -【補足】Xamarinについて
        ・Xamarinとは
            -Mono。MSに買収された
        ・Xamarinネイティブ（他の呼び方もあり）
            -Android/iOS向け。UIはプラットフォームごとに用意
        ・Xamarin.Forms（UWP対応はこっち）
            -Android/iOS/UWP（/Mac/WPFも？）向け。UIも共通だがプラットフォーム固有コードも書ける
            -Mac/WPFの実情。
            -2つの開発手法があるっぽい（サンプル作ったときに選択した）
            -C#/XAMLだが、XAML部はMS純正UWPのものとは異なる。（似てはいる。）
---
・試作
    -純正UWP
        ライブラリ読み込み→API呼び出しまで
    -Xamarin（Step2での検討？いやいや、UWPだからこっち）
        （できれば）ライブラリ読み込み→API呼び出しまで
    -【番外編】WPF（Stepでの検討？本来はそうだが、ここにまとめるのがよいか。。？）
        XAML部がどれも違うよ、ということが言いたいがため。XAML部比較があるとベスト
---
Step2
・検討プラットフォームの選定（Bridgeは候補から消えるかも）
    -純正UWP（C#/XAML）
    -Xamarin.Forms
    -DesktopBridge/MSIX
・SetupForFuture
    -ForWin
        1.MS→MS（7～10S対応）
            -Xamarin.Forms.WPF/Xamarin.Forms.UWP
            -DesktopBridge
        2.MS→NS（7～10S対応）
            -
        3.MS→MS（非10S）+NS（10S対応）
        4.MS→SetupInEveryApp（10S対応）
    -ForMobile
        1.CPI→CPI
        2.CPI→NS
    -4×2で8

        

---
#備忘メモ
##管理者権限の話
-UWPアプリでは管理者権限の必要とする機能は「原則」使用禁止
-制限付き機能として「昇格」を使うことができれば、使用可能（Store申請はまず通らない？
-DesktopBridgeでStore配布可能App作っても、「管理者として実行」しなければならない。標準ユーザーでサインインしている場合、右クリックしてもこの項目が出てこない？
##.Netの話
-.NetFramework/.NetCore/.NetStandardの話はまとめておきたい
-FrameworkはWinのみ、Coreは他のOSにも対応、StandardはCoreとFramework共通部分？
-ライブラリ作成に関係するトピック
