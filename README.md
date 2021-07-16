# A C++/WinRT UWP Hello, World! app for retargeting to Reunion/WinUI/Win32

A simple UWP Hello, World! app ready to retarget to Reunion/WinUI/Win32.

This project was created from the **Blank App (C++/WinRT)** project template. It targets the most recent release (not preview) of the platform (currently 19041).

**Note**. We could have chosen other UI types to showcase in the UI here. But be aware that WinUI doesn't yet support Maps, MediaElement, nor InkCanvas.

## How we added the file type association

Open `Package.appxmanifest`. In **Declarations**, choose **File Type Associations**, and click **Add**. Set the following properties.

**Display name**: Hello File
**Name**: hellofile
**File type**: .hi

To register the file type association, build the app, launch it, and close it.

For this project type, we had to add the **App::OnFileActivated** handler.

## To test

In your local **Documents** folder (or anywhere else, if you like), create a new **Text Document** file, and name it *MyHelloFile.hi*.

Double-click on the file, and confirm that the app launches and displays the UI (if it sticks on the splash screen, then the implementation of **OnFileActivated** is missing or incorrect.

Resize the window, and confirm that the correct visual states are applied.

Click the button, dismiss the message dialog, pick a folder containing files, and confirm that the first three filenames are displayed in the list box.

Next, for instructions on retargeting the app to Reunion/WinUI/Win32, see [RetargetToReunionCppWin32](https://github.com/stevewhims/RetargetToReunionCppWin32).
