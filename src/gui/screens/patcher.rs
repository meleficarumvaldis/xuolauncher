use iced::widget::{column, container, progress_bar, row, text, vertical_space};
use iced::{Alignment, Element, Length, Color};

use crate::core::message::Message;
use crate::core::state::{PatcherState, PatcherStep};
use crate::gui::theme;

pub fn view(state: &PatcherState) -> Element<Message> {
    // In iced 0.13, text style takes a closure or a built-in function that returns Color/Style.
    // For simple colors, we can use a closure: `| _theme | color`

    let title = text("Updating Game Client")
        .size(theme::FONT_SIZE_HEADER)
        .style(|_theme| text::Style { color: Some(theme::TEXT_BRIGHT) });

    let status_text = match state.state {
        PatcherStep::Checking => format!("Verifying files... ({}/{})", state.processed_files, state.total_files),
        PatcherStep::Downloading => format!(
            "Downloading: {} - {}",
            state.current_file, state.download_speed
        ),
    };

    let status_row = row![
        text(status_text).style(|_theme| text::Style { color: Some(theme::TEXT_BRIGHT) }),
        text(format!("Remaining: {}", state.files_remaining)).style(|_theme| text::Style { color: Some(theme::TEXT_MUTED) })
    ]
    .spacing(theme::SPACING_DEFAULT)
    .width(Length::Fill)
    .align_y(Alignment::Center);

    let progress_indicator = progress_bar(0.0..=1.0, state.progress)
        .height(10.0)
        .style(progress_bar::primary);

    let content = column![
        title,
        vertical_space().height(theme::SPACING_DEFAULT),
        status_row,
        vertical_space().height(theme::SPACING_SMALL),
        progress_indicator,
    ]
    .spacing(theme::SPACING_DEFAULT)
    .padding(theme::SPACING_DEFAULT)
    .max_width(600);

    container(content)
        .width(Length::Fill)
        .height(Length::Fill)
        .center_x(Length::Fill)
        .center_y(Length::Fill)
        .style(crate::gui::style::main_container_style)
        .into()
}
