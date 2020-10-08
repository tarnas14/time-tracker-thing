# working with containerized flutter

This project sets out to allow developing a mobile project without having to install any dependencies on the developer's machine.
Dependencies and environment is dockerized and allows running the application on a connected phone from the container.

## run
```
docker-compose run --rm client-mobile
```
this will run an interactive shell in `/build` directory where you can interact with flutter etc

first-time setup on the container

to install packages and then run the application
```
flutter pub get
flutter run
```

## troubleshooting

check if everything is working correctly:
```
flutter doctor
```
ideally the output will be something like this:
```
root@80e81def1c64:/build# flutter doctor
Doctor summary (to see all details, run flutter doctor -v):
[✓] Flutter (Channel unknown, 1.20.4, on Linux, locale en_US.UTF-8)

[✓] Android toolchain - develop for Android devices (Android SDK version
    30.0.2)
[!] Android Studio (not installed)
[✓] Connected device (1 available)
```

if the device is not connected, try restarting adb
```
adb start-server
```

## Windows loosers

The only way is to install `platform-tools` and use network connection for development purposes. To achieve that, connect your Android device and then

```
adb devices
adb tcpip 5555
```

There should be your device listed. Check it's IP in System tab in settings then:

```
adb connect 192.and.roi.dip:5555
```

it's connected, so should work. Run the same connect command in flutter docker image.

---

# build

A new Flutter project.

## Getting Started

This project is a starting point for a Flutter application.

A few resources to get you started if this is your first Flutter project:

- [Lab: Write your first Flutter app](https://flutter.dev/docs/get-started/codelab)
- [Cookbook: Useful Flutter samples](https://flutter.dev/docs/cookbook)

For help getting started with Flutter, view our
[online documentation](https://flutter.dev/docs), which offers tutorials,
samples, guidance on mobile development, and a full API reference.
