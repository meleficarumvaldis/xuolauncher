use iced::widget::{column, container, progress_bar, row, text, text_input, vertical_space};
use iced::{Alignment, Element, Length, Color};

use crate::core::message::Message;
use crate::core::state::{PatcherState, PatcherStep};
use crate::gui::theme;
use crate::gui::style;

pub fn view(state: &PatcherState) -> Element<Message> {
    let title = text("Updating Game Client")
        .size(theme::FONT_SIZE_HEADER)
        .color(theme::TEXT_BRIGHT);

    let status_text = match state.state {
        PatcherStep::Checking => format!("Verifying files... ({}/{})", state.processed_files, state.total_files),
        PatcherStep::Downloading => format!(
            "Downloading: {} - {}",
            state.current_file, state.download_speed
        ),
    };

    let status_row = row![
        // Selectable status text
        text_input("", &status_text)
            .style(style::transparent_text_input_style)
            .width(Length::Fill),

        text(format!("Remaining: {}", state.files_remaining)).color(theme::TEXT_MUTED)
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
    .max_width(600);

    // Wrapped in a Card
    let card = container(content)
        .style(style::card_style)
        .padding(30);

    container(card)
        .width(Length::Fill)
        .height(Length::Fill)
        .center_x(Length::Fill)
        .center_y(Length::Fill)
        .style(style::main_container_style)
        .into()
}
