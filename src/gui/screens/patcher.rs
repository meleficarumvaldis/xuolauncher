use iced::widget::{column, container, progress_bar, row, text, text_input, vertical_space};
use iced::{Alignment, Element, Length};
use crate::core::message::Message;
use crate::core::state::{PatcherState, PatcherStep};
use crate::gui::{theme, style};

pub fn view(state: &PatcherState) -> Element<'_, Message> {
    let title = text("Aktualisiere Spiel")
        .size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT);

    // Zeige Status-Text (z.B. "Lade Manifest...") im Checking-Step
    let status_text = match state.state {
        PatcherStep::Checking => state.status_text.clone(),
        PatcherStep::Downloading => format!("Lade herunter: {} - {}", state.current_file, state.download_speed),
    };

    let remaining_text = if state.state == PatcherStep::Downloading {
         format!("Verbleibend: {}", state.files_remaining)
    } else { String::new() };

    let status_row = row![
        text_input("", &status_text).style(style::transparent_text_input_style).width(Length::Fill),
        text(remaining_text).color(theme::TEXT_MUTED)
    ].spacing(theme::SPACING_DEFAULT).align_y(Alignment::Center);

    let content = column![
        title,
        vertical_space().height(theme::SPACING_DEFAULT),
        status_row,
        vertical_space().height(theme::SPACING_SMALL),
        progress_bar(0.0..=1.0, state.progress).height(10.0).style(progress_bar::primary),
    ].spacing(theme::SPACING_DEFAULT).max_width(600);

    container(container(content).style(style::card_style).padding(30))
        .width(Length::Fill).height(Length::Fill)
        .center_x(Length::Fill).center_y(Length::Fill)
        .style(style::main_container_style).into()
}