#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::HelloWorldCppUWP::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();

        VisualStateManager::GoToState(*this, L"DefaultOrientation", false);
        VisualStateManager::GoToState(*this, L"DefaultSize", false);

        SizeChanged({ this, &MainPage::SizeChangedHandler });
    }

    winrt::fire_and_forget MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto showDialog{ Windows::UI::Popups::MessageDialog(L"Please be sure to pick a folder that contains files") };
        co_await showDialog.ShowAsync();

        auto folderPicker{ Windows::Storage::Pickers::FolderPicker() };
        folderPicker.SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId::ComputerFolder);
        folderPicker.FileTypeFilter().Append(L"*");

        Windows::Storage::StorageFolder folder{ co_await folderPicker.PickSingleFolderAsync() };
        if (folder)
        {
            // Application now has read/write access to all contents in the picked folder
            // (including other sub-folder contents)
            Windows::Storage::AccessCache::StorageApplicationPermissions::FutureAccessList().AddOrReplace(L"PickedFolderToken", folder);

            // Get the first 3 files in the folder.
            Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile> filesInFolder{
                co_await folder.GetFilesAsync(Windows::Storage::Search::CommonFileQuery::DefaultQuery, 0, 3) };

            co_await winrt::resume_foreground(this->Dispatcher());
            fileListLB().Items().Clear();

            for (Windows::Storage::StorageFile const& fileInFolder : filesInFolder)
            {
                fileListLB().Items().Append(winrt::box_value(fileInFolder.Name().c_str()));
            }
        }
    }

    void MainPage::SizeChangedHandler(IInspectable const&, SizeChangedEventArgs const& e)
    {
        if (e.NewSize().Width < e.NewSize().Height)
        {
            VisualStateManager::GoToState(*this, L"PortraitOrientation", false);
        }
        else
        {
            VisualStateManager::GoToState(*this, L"DefaultOrientation", false);
        }

        if (e.NewSize().Width < 950 || e.NewSize().Height < 500)
        {
            VisualStateManager::GoToState(*this, L"SmallSize", false);
        }
        else
        {
            VisualStateManager::GoToState(*this, L"DefaultSize", false);
        }
    }
}
