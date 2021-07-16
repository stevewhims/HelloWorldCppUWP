#pragma once

#include "MainPage.g.h"

namespace winrt::HelloWorldCppUWP::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        winrt::fire_and_forget ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
        void SizeChangedHandler(Windows::Foundation::IInspectable const&, Windows::UI::Xaml::SizeChangedEventArgs const&);
    };
}

namespace winrt::HelloWorldCppUWP::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
