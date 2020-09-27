# working with containerized flutter

this will run an interactive shell in `/build` directory where you can interact with flutter etc
```
docker-compose run --rm client-mobile
```
to install packages and then run the application
```
flutter pub get
flutter run
```
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
