# A C++/WinRT UWP Hello, World! app for retargeting to Reunion/WinUI/Win32

A simple C++/WinRT UWP Hello, World! app ready to port to the Windows App SDK.

## How the project was created

This project was created from the **Blank App (C++/WinRT)** [Visual Studio](https://visualstudio.microsoft.com/downloads/) project template. The project targets the most recent release (not preview) of the platform (19041 at time of writing).

**Note**. We could have chosen other UI types to showcase in the UI here. But be aware that WinUI doesn't yet support Maps, MediaElement, nor InkCanvas.

### How we added the file type association

Open `Package.appxmanifest`. In **Declarations**, choose **File Type Associations**, and click **Add**. Set the following properties.

**Display name**: Hello File
**Name**: hellofile
**File type**: .hi

To register the file type association, build the app, launch it, and close it.

For this project type, we had to add the **App::OnFileActivated** handler.

## To test the app

In your local **Documents** folder (or anywhere else, if you like), create a new **Text Document** file, and name it *MyHelloFile.hi*.

Double-click on the file, and confirm that the app launches and displays the UI (if it sticks on the splash screen, then the implementation of **OnFileActivated** is missing or incorrect.

Resize the window, and confirm that the correct visual states are applied.

Make sure you can use the flip view to navigate to each of the four images.

Click the button, dismiss the message dialog, pick a folder containing files, and confirm that the first three filenames are displayed in the list box.

## Porting to app to the Windows App SDK

For instructions on porting the app to the Windows App SDK, see [HelloWorldCppWindowsAppSDK](https://github.com/stevewhims/HelloWorldCppWindowsAppSDK).
