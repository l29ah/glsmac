#pragma once

#include "ui/theme/Theme.h"

#include "Style.h"
#include "BottomBar.h"
#include "Popup.h"

namespace game {
namespace world {
namespace ui {
namespace style {

CLASS( Theme, ::ui::theme::Theme )
	Theme();

protected:
	
	struct {
		Style style;
		BottomBar bottom_bar;
		Popup popup;
	} m_styles;
};

}
}
}
}
